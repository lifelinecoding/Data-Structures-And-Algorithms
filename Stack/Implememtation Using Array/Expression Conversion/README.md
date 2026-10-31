# Expression conversion

These programs convert among infix, postfix, and prefix expression notation. A stack is used to manage operators and intermediate expressions.

## Suggested learning sequence

1. [`InfixToPostfix.c`](./InfixToPostfix.c) — begin with precedence-driven operator handling.
2. [`InfixToPrefix.c`](./InfixToPrefix.c) — compare conversion from infix to prefix.
3. [`PostfixToInfix.c`](./PostfixToInfix.c) and [`PrefixToInfix.c`](./PrefixToInfix.c) — rebuild infix expressions from the other forms.
4. [`PostfixToPrefix.c`](./PostfixToPrefix.c) and [`PrefixToPostfix.c`](./PrefixToPostfix.c) — convert directly between postfix and prefix.

## Key ideas

- Infix places operators between operands; postfix places them after operands; prefix places them before operands.
- Conversion depends on operator precedence, associativity, and parentheses.
- Trace stack contents after every token using a small expression before trying longer input.
- Check each program's supported operands and operators; these examples may not implement a full expression grammar.
