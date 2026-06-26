# Bread Language — Formal Grammar (Draft)

This is EBNF, not a programming language — nothing compiles this file. It's the
written-down structure of Bread, for you to build `bread-parser.h` against and
to hand-trace real `.bd` lines through before trusting the parser.

## Notation key

- `::=` — "is defined as"
- `|` — alternative ("either / or")
- `( ... )` — grouping
- `*` — zero or more repetitions of whatever it follows
- `+` — one or more repetitions
- `?` — optional (zero or one)
- `"..."` — a literal terminal (a keyword or symbol straight out of `standard-constants-main.h`)
- `UPPERCASE` words (`Number`, `Identifier`, `StringLiteral`) — terminal categories your lexer already produces, not literal text

---

## 0. Terminals

These come straight from `standard-constants-main.h` and `bread-lexer.h`. This
section should stay a mirror of that file — if you add a token there, add it
here too.

**Keywords:** `int` `float` `double` `bool` `char` `str` `Large` `if` `else`
`elseIf` `inline` `switch` `case` `default` `for` `while` `do` `break`
`continue` `new` `true` `false` `class` `group` `public` `private`
`protected` `try` `catch` `except` `const` `rigid` `return` `auto` `and`
`or` `xor` `sizeOf` `extend` `null` `about_author`

**Unary operators:** `--` `++` `!` `~` `$` `ascii` `anti_ascii`

**Binary operators:** `+` `-` `*` `/` `//` `%` `==` `!=` `<` `>` `<=` `>=`
`&&` `||` `&` `|` `^` `>>` `<<` `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=` `^=`
`<<=` `>>=` `?` `:` `.` `->` `(` `)` `()` `{}` `{` `}` `[` `]` `[]`

**Terminator:** `>~`

**Lexer-level categories (not literal text):** `Number`, `Identifier`,
`StringLiteral`

---

## 1. Program

```
program ::= statement*
```

---

## 2. Statements

```
statement     ::= varDecl
                 | exprStmt
                 | ifStmt
                 | whileStmt
                 | doWhileStmt
                 | forStmt
                 | switchStmt
                 | breakStmt
                 | continueStmt
                 | returnStmt
                 | tryStmt
                 | block

block         ::= "{" statement* "}"

type          ::= "int" | "float" | "double" | "bool" | "char" | "str" | "Large" | "auto"
declModifier  ::= "const" | "rigid"

varDecl       ::= declModifier? type Identifier ("=" expression)? ">~"
exprStmt      ::= expression ">~"

ifStmt        ::= "if" "(" expression ")" block elseIfClause* elseClause?
elseIfClause  ::= "elseIf" "(" expression ")" block
elseClause    ::= "else" block

whileStmt     ::= "while" "(" expression ")" block
doWhileStmt   ::= "do" block "while" "(" expression ")" ">~"

forStmt       ::= "for" "(" forInit? <SEP> expression? <SEP> forUpdate? ")" block
forInit       ::= type Identifier "=" expression | expression
forUpdate     ::= expression

switchStmt    ::= "switch" "(" expression ")" "{" caseClause* defaultClause? "}"
caseClause    ::= "case" expression ":" statement*
defaultClause ::= "default" ":" statement*

breakStmt     ::= "break" ">~"
continueStmt  ::= "continue" ">~"
returnStmt    ::= "return" expression? ">~"

tryStmt       ::= "try" block catchClause
catchClause   ::= "catch" "(" Identifier ")" block
```

Notes on what's deliberately settled here:

- **`ifStmt` has no dangling-else problem.** `elseIf`/`else` are tied directly
  into the `ifStmt` rule rather than floating as independent statements, so
  there's never an ambiguity about which `if` an `else` belongs to. That was
  a real design win from making `elseIf` its own keyword instead of two
  tokens — keep it.
- `<SEP>` in `forStmt` is a placeholder, not a token — see Open Decisions
  below, it isn't resolved yet.
- `except` does not appear anywhere above — see Open Decisions.

---

## 3. Expressions

One precedence layer per row of your operator table, loosest-binding on the
outside, tightest on the inside, every layer falling through to the next when
its own operator isn't present:

```
expression          ::= assignExpr

assignExpr           ::= ternaryExpr (assignOp assignExpr)?      (* right-associative *)
assignOp             ::= "=" | "+=" | "-=" | "*=" | "/=" | "%=" | "&=" | "|=" | "^=" | "<<=" | ">>="

ternaryExpr          ::= logicOrExpr ("?" expression ":" expression)?

logicOrExpr          ::= logicAndExpr (("||" | "or") logicAndExpr)*
logicAndExpr         ::= bitOrExpr (("&&" | "and") bitOrExpr)*

bitOrExpr            ::= bitXorExpr ("|" bitXorExpr)*
bitXorExpr           ::= bitAndExpr (("^" | "xor") bitAndExpr)*
bitAndExpr           ::= equalityExpr ("&" equalityExpr)*

equalityExpr         ::= relationalExpr (("==" | "!=") relationalExpr)*
relationalExpr       ::= shiftExpr (("<" | ">" | "<=" | ">=") shiftExpr)*
shiftExpr            ::= additiveExpr (("<<" | ">>") additiveExpr)*

additiveExpr         ::= multiplicativeExpr (("+" | "-") multiplicativeExpr)*
multiplicativeExpr   ::= unaryExpr (("*" | "/" | "//" | "%") unaryExpr)*

unaryExpr            ::= ("--" | "++" | "!" | "~" | "$" | "ascii" | "anti_ascii" | "-")? postfixExpr
postfixExpr          ::= primary ( "." Identifier | "->" Identifier | "(" argList? ")" | "[" expression "]" )*

primary              ::= Number
                        | StringLiteral
                        | Identifier
                        | "true" | "false" | "null"
                        | "sizeOf" "(" expression ")"
                        | "(" expression ")"

argList               ::= expression ("," expression)*    (* see Open Decisions: no comma token exists yet *)
```

Two parsing subtleties worth knowing about before you write `bread-parser.h`:

- **`-` is both unary and binary.** It's in `unaryExpr`'s prefix set *and* in
  `additiveExpr` as subtraction. The standard fix: only try the unary-prefix
  branch when you're expecting a fresh operand (start of an expression,
  right after `(`, right after another operator) — not right after a
  completed operand. This is a well-known precedence-climbing gotcha, not a
  bug in the grammar.
- **`and`/`or`/`xor` vs `&&`/`||`/`^`** are written above as exact synonyms
  at the same precedence level (Python-style word aliases for the symbolic
  operators). That's an assumption on my part, not a decision you've
  confirmed — see Open Decisions.

---

## 4. Open Decisions

These keywords/constructs exist as terminals but don't have committed grammar
rules yet, because the design choice itself hasn't been made. Resolve before
the parser stage touches them (Stage 2.5 specifically needs #1 below).

1. **Function declarations.** No keyword exists for this at all yet (`return`
   exists, but nothing declares a function). You need to pick a keyword and
   syntax, then add the keyword to `standard-constants-main.h`, before
   `funcDecl` can be written here. A strawman to react to, not a decision:
   ```
   funcDecl ::= "func" Identifier "(" paramList? ")" ("->" type)? block
   paramList ::= type Identifier ("," type Identifier)*
   ```
2. **`catch` vs `except`.** Both exist as keywords doing what looks like the
   same job. `tryStmt` above only uses `catch`. Decide: drop `except`, or
   give it a distinct meaning (e.g. a `finally`-equivalent that always runs)?
3. **No comma token.** `argList` (function-call arguments) and `forStmt`'s
   three clauses both want a separator, and `,` isn't in your binary
   operators list at all. Needs adding to `standard-constants-main.h` as its
   own terminal before either rule is real. The `<SEP>` placeholder in
   `forStmt` above is most likely this same comma, once it exists — though
   some languages use `>~` even there since it's already "statement-like";
   worth deciding deliberately rather than defaulting.
4. **`and`/`or`/`xor` vs `&&`/`||`/`^`.** Confirmed as exact synonyms in the
   draft above — flag this back to me if that's not actually what you want
   (e.g. if you intended different precedence for the word forms, like
   Python's `and`/`or` sitting *below* assignment).
5. **`about_author` and `group`.** No rules written for either — semantics
   genuinely undecided. `about_author` looks like file-level metadata
   (maybe `"about_author" StringLiteral ">~"` at the top of a file?) but
   that's a guess, not yours.
6. **OOP block — `class`, `extend`, `public`, `private`, `protected`,
   `new`.** Deliberately left out of this grammar entirely. Per the
   roadmap, this is Stage 5.4 — a stretch goal once Stages 2–4 produce a
   working procedural language. Don't let it block anything above.

---

## 5. Worked derivation (validation by hand-trace)

Tracing `if ( x > 3 ) { x = x + 1 >~ }` through the rules above, to confirm
it bottoms out cleanly with no ambiguity:

```
statement → ifStmt
ifStmt    → "if" "(" expression ")" block          (no elseIfClause/elseClause present)

  expression for "x > 3":
    expression → assignExpr → ternaryExpr → logicOrExpr → logicAndExpr
      → bitOrExpr → bitXorExpr → bitAndExpr → equalityExpr → relationalExpr
    relationalExpr → shiftExpr ">" shiftExpr
      left shiftExpr falls through every layer with no match → primary → Identifier ("x")
      right shiftExpr falls through every layer with no match → primary → Number ("3")

  block → "{" statement* "}"
    statement → exprStmt → expression ">~"
      expression for "x + 1":
        assignExpr → ... → additiveExpr
        additiveExpr → multiplicativeExpr "+" multiplicativeExpr
          left  → ... → primary → Identifier ("x")
          right → ... → primary → Number ("1")
      ">~" consumed as exprStmt's terminator
```

Every layer with no matching operator at that precedence "falls through"
silently to the next rule down — that's not a special case, it's what the
grammar shape always does, and it's exactly what becomes an early `return`
inside each parsing function once you write `bread-parser.h`. If you ever
trace a real line and get stuck on which rule applies next, that's a genuine
ambiguity in the grammar, not a tracing mistake — come back here and fix the
rule before writing the parser code against it.