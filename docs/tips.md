# Better solutions' lexer actions looked like
* ...regex... `{ return token(TERMSYM); }`
    * where `token()` allocates a token structure, sets a global variable to point to it, and returns the same integer category that it is passed from `yylex()`, so `yylex()` in turn returns this value.
* Put in enough line breaks.
* Use <= 80 columns in your code, so that it prints readably.
* Comment non-trivial helper functions.
    * Comment non-trivial code.
    * Comment appropriate for a CS professional reader, not a newbie tutorial. I know what `i++` does, you do not have to tell me.
    * Do not leave in commented-out debugging code or whatever.
* Fancier formatting might calculate field widths from actual data and use a variable to specify field widths in the `printf`.
* Remind yourself of the difference between `NULL` and '`\0'` and `0`
    * `NULL` is used for pointers. The `NULL` byte '`\0`' terminates strings. `0` is a different size from `NULL` on many 64-bit compilers. Beware.
* Avoid `O(n2)` or worse, if at all possible
* It is possible to write bad algorithms that work, but it is better to write good algorithms that work.
* Avoid big quantities of duplicate code
* Use a switch when appropriate instead of long chain of if-statements
    * Long chains of if statements are actually slow and less readable.
* On strings, allocate one byte extra for `NULL`.
    * This common `445` problem causes valgrind trouble, memory violations etc.
* On all pointers, don't allocate and then just point the pointer someplace else
    * This common student error results in, at least, a memory leak.
* Don't allocate the same thing over and over unless copies may need to be modified.
    * This is often a performance problem.
    * Check all allocations and `fopen()` calls for `NULL` return (good to have helper functions).
* `C` library functions can fail. Expect and check for that.
* Beware losing the base pointer that you allocated.
* You can only `free()` if you still know where the start of what you allocated was.
* Avoid duplicate calls to `strlen()`
    * especially in a loop! (Its `O(n2)`)
* Use `strcpy()` instead of `strncpy()`
    * unless you are really copying only part of a string, or copying a string into a limited-length buffer.
* You can't `malloc()` in a global initializer
    * `malloc()` is a runtime allocation from a memory region that does not exist at compile or link time.
    * Globals can be initialized, but not to point at memory regions that do not exist until runtime.
* Don't use raw constants like `260`
    * use symbolic names, like `LEFTPARENTHESIS` or `LP`
* The vertical bar (`|`) means nothing inside square brackets!
    * Square brackets are an implicit shortcut for a whole lot of ORs
* If you don't allocate your token inside `yylex()` actions...you'll have to go back and do it.
