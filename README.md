# cpp-primer

This is a repo only meant for personal use.
For anyone interested in the proper solution to all exercises, [`jaege`](https://github.com/jaege/Cpp-Primer-5th-Exercises)s solution are recommended

## Compiling

```
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -fno-common -Wconversion -g3 -Os -o $SRC $SRC.cxx
```

[Best and worst compiler flags](https://interrupt.memfault.com/blog/best-and-worst-gcc-clang-compiler-flags)

## Issues with setting up Visual studio code

- Problem: `python` pointing at `/usr/bin/python`
- Solution: The `conda` way of exporting the path in `.zshrc` may not work

- Problem: The symbols are missing from the powerline
- Solution: Use [`nerd-font`](https://github.com/ryanoasis/nerd-fonts/#option-3-install-script) as explained [here](https://gist.github.com/480/3b41f449686a089f34edb45d00672f28)

```sh
brew tap homebrew/cask-fonts
brew cask install font-hack-nerd-font
```

and add

```
"terminal.integrated.fontFamily": "Hack Nerd Font"
```

to `settings.json`

- Problem: Need to save manually
- Solution: `File` -> `Auto save`
