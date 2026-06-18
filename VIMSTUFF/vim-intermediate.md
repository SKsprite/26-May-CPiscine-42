# Vim Intermediate Notes

Assumes familiarity with basics up to `:set listchars=tab:>\ ,trail:-` and swapping colorschemes.

---

## 1. Autocomplete

Vim has built-in completion triggered in **Insert mode** with `Ctrl+x` followed by a second key.

| Shortcut | What it completes from |
|---|---|
| `Ctrl+n` | Keywords across all open buffers and included files (forward) |
| `Ctrl+p` | Same as above, backward |
| `Ctrl+x Ctrl+n` | Keywords in the current file only |
| `Ctrl+x Ctrl+f` | File paths |
| `Ctrl+x Ctrl+]` | Tags (see Section 2) |
| `Ctrl+x Ctrl+o` | Omni-completion — language-aware (needs `filetype plugin on`) |

Once the completion menu pops up:
- `Ctrl+n` / `Ctrl+p` — cycle through suggestions
- `Enter` or keep typing — confirm
- `Ctrl+e` — dismiss the menu and go back to what you typed

**Enabling omni-completion** (add to `~/.vimrc`):
```vim
filetype plugin on
set omnifunc=syntaxcomplete#Complete
```
For C specifically, Vim ships with `ccomplete`, which activates automatically when `filetype plugin on` is set.

---

## 2. Navigate to Function / Variable Declaration

### `gd` and `gD`

No setup needed. Place your cursor on a name and press:

- `gd` — jump to the **local** declaration (searches from the top of the function scope)
- `gD` — jump to the **global** declaration (searches from the top of the file)

Works instantly but is purely text-based — it finds the first place the word appears, which is usually the declaration.

### Tags (the proper way)

Tags give Vim a real index of every function, struct, and variable across your whole project.

**Step 1 — generate the tags file** (run this in your terminal at the project root):
```sh
ctags -R .
```
This creates a `tags` file. Re-run it whenever you add new functions.

**Step 2 — use it in Vim:**

| Shortcut | Action |
|---|---|
| `Ctrl+]` | Jump to the definition of the word under the cursor |
| `Ctrl+t` | Jump back to where you came from |
| `:tag myFunc` | Jump to `myFunc` directly |
| `:tnext` / `:tprev` | If multiple matches exist, cycle through them |

**Step 3 — tell Vim where to look for the tags file** (add to `~/.vimrc`):
```vim
set tags=./tags,tags;$HOME
```
The `;$HOME` part makes Vim walk up the directory tree looking for a `tags` file, so it works from any subdirectory.

### Jump list

Regardless of how you got somewhere, Vim tracks your cursor history:
- `Ctrl+o` — jump to the previous position
- `Ctrl+i` — jump forward again

These work across files and are useful after any `gd`, `Ctrl+]`, or search jump.

---

## 3. Custom Colors for Types and Functions

You already know how to set a colorscheme. This builds on that — you can teach Vim about your own types and give them whatever color you want, without touching the colorscheme file itself.

### How Vim color highlighting works

Every piece of highlighted text belongs to a **syntax group** (e.g. `Type`, `Function`, `Keyword`). Your colorscheme assigns colors to those groups. You can:
1. Define new syntax groups that match your custom names.
2. Assign colors to those groups, or link them to an existing group.

### Step 1 — find out what group is under your cursor

Add this to `~/.vimrc`:
```vim
nnoremap <F10> :echo synIDattr(synID(line('.'), col('.'), 1), 'name')<CR>
```
Press `F10` on any word to see its syntax group name. Useful for knowing what to link to.

### Step 2 — create a syntax file for your filetype

Put custom syntax rules in `~/.vim/after/syntax/<filetype>.vim`.
The `after/` directory loads *after* the built-in syntax, so your rules won't get overwritten.

Example for C (`~/.vim/after/syntax/c.vim`):
```vim
" Match specific type names you defined
syntax keyword myCustomType MyStruct MyEnum MyContext

" Match function names by pattern (any identifier followed by '(')
syntax match myCustomFunc /\<[a-z_]\+\ze(/
```

- `syntax keyword` — matches exact words
- `syntax match` — matches a regex pattern
- `\ze` — a zero-width "end here" marker (matches up to but not including the `(`)

### Step 3 — assign colors to your groups

Add `highlight` commands in `~/.vim/after/syntax/c.vim` (or in your `~/.vimrc` inside an `autocmd`):

```vim
" Define colors directly
highlight myCustomType ctermfg=214 guifg=#ffaf00
highlight myCustomFunc ctermfg=81  guifg=#5fd7ff

" OR just link your group to an existing colorscheme group
highlight link myCustomType Type
highlight link myCustomFunc Function
```

- `ctermfg` — color index for the 256-color terminal palette
- `guifg` — hex color for GUI Vim or terminals with true color
- `ctermbg` / `guibg` — background color
- `cterm=bold` / `gui=bold` — bold, italic, underline, etc.

### Enabling true color (so `guifg` hex values work in the terminal)

```vim
" in ~/.vimrc
set termguicolors
```

Only add this if your terminal supports true color (most modern ones do: iTerm2, Kitty, Alacritty, Windows Terminal).

### Keeping highlight colors after a colorscheme change

Colorschemes reset all highlights when loaded. To make yours stick, use an `autocmd`:

```vim
" in ~/.vimrc
augroup MyHighlights
  autocmd!
  autocmd ColorScheme * highlight myCustomType ctermfg=214 guifg=#ffaf00
  autocmd ColorScheme * highlight myCustomFunc ctermfg=81  guifg=#5fd7ff
augroup END
```

`ColorScheme *` fires every time any colorscheme is applied, re-applying your overrides on top.

---

## Quick Reference Card

```
INSERT MODE COMPLETION
  Ctrl+n / Ctrl+p     keyword complete (all buffers)
  Ctrl+x Ctrl+n       keyword complete (this file)
  Ctrl+x Ctrl+f       filename complete
  Ctrl+x Ctrl+o       omni-complete (language-aware)

NAVIGATION
  gd                  go to local declaration
  gD                  go to global declaration
  Ctrl+]              jump to tag definition
  Ctrl+t              jump back from tag
  Ctrl+o / Ctrl+i     jump backward / forward in history

SYNTAX GROUPS
  :echo synIDattr(synID(line('.'), col('.'), 1), 'name')
                      show highlight group under cursor

HIGHLIGHT COMMANDS
  syntax keyword <group> Word1 Word2
  syntax match <group> /pattern/
  highlight <group> ctermfg=214 guifg=#ffaf00
  highlight link <group> Type
```
