# mixfix shell (mfsh)

a shell made specifically to prove some people wrong

---

mfsh, as a language, is a lisp-inspired (but probably more along the lines of ruby) lang with aspects of functional programming.

mfsh, as a shell,
- makes no attempt at being POSIX-compliant
- will not even try to deal with bash scripts
- does not (yet?) support environment variables, do `bash -e "<cmd>"` or something if you want shell-specific ones
  - however during the early testing stage it's currently in i have it using `execvp`, so at least `PATH` should be inherited?
- does not have tab completion
- may or may not have syntax highlighting, depending on the time you read this
- is an experiment, and should not be used for any potentially destructive operations

## syntax (unfinished)

`symbol`
- if top-level / interactive and `symbol` is a variable, print the variable (equivalent to `print show symbol`)
- otherwise if `symbol` is a variable, it evaluates to its value, printing nothing
- if `symbol` is a function, attempt to call the function
- if `symbol` is an alias, replace it with the text it represents, and evaluate from there
- otherwise if `symbol` is unbound, call it as an executable (equivalent to `sh symbol` or `sh "symbol"`)

`{ a ; b ; ... }` - equivalent of any lisp's `progn` (intermediate forms are only executed, not returned) (the interactive shell is wrapped in this)

`lambda (a b ...) (y z ...) (...)` - define a lambda (evaluates to a function object)
`a b ...` are arguments that come on the left side of the function, and `y z ...` come on the right side, as they would in any normal language

`a b ... call fn y z ...` - call function object (yes, this syntax is bad. i don't know how to make it better, if anyone else does raise an issue!)

`let (symbol value) ...` - bind `symbol` to `value`. scoped within parens.

`let* ((symbol-0 value-0) (symbol-1 value-1) ...) ...` - bind `symbol-*`s to corresponding `value-*`s. scoped within parens.

// todo: add paren rules and function quotation syntax

## builtins

(let `strbol` expand to `(string | symbol)` within this section)

```
sh (cmd : strbol) (&optional args : list strbol | &rest strbol)
-> (tuple4 (stdout : stream) (stdin : stream) (stderr : stream) (pid : int))
```
execute executable (via `exec`, not a shell, so the name is a bit misleading)

// todo

## milestones

// todo

## community

technically, there is none, and you could make the argument that this is an overdone shitpost

...

join the (more general) discord anyway: https://discord.gg/DAuUSrr3yz

## license

GPLv3+, of course!

