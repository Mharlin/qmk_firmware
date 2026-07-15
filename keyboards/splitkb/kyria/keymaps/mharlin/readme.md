# Kyria Keymap - mharlin

A Colemak-DH based keymap with home row mods and multiple layers.

## Features

- **Colemak-DH** base layout
- **Home row mods** (GUI, Alt, Ctrl, Shift)
- **Tap dance** for layer switching and special functions
- **Swedish characters** (Å, Ä, Ö) on the NUM layer
- **App launcher macros** (VSCode, IntelliJ, Zen, Slack, Ghostty, Logseq, Claude)
- **Mac Fn key** via double-tap Backspace (requires Karabiner-Elements mapping F13 to Fn)

## Layers

1. **BASE** - Colemak-DH with home row mods
2. **NAV** - Navigation, app launchers
3. **MOUSE** - Mouse movement and scrolling
4. **BUTTON** - Cut/Copy/Paste, mouse buttons
5. **NUM** - Numbers and Swedish characters
6. **SYM** - Symbols
7. **FUN** - Function keys
8. **MEDIA** - Media controls

## Base Layer (Colemak-DH)

```
,----------------------------------.          ,----------------------------------.
|   Q  |   W  |   F  |   P  |   B  |          |   J  |   L  |   U  |   Y  | '  " |
|------+------+------+------+------|          |------+------+------+------+------|
|   A  |   R  |   S  |   T  |   G  |          |   M  |   N  |   E  |   I  |   O  |
|------+------+------+------+------+          +------+------+------+------+------|
|   Z  |   X  |   C  |   D  |   V  |          |   K  |   H  | ,  < | . >  | /  ? |
`-------------+------+------+------+---|   |--+------+------+------+-------------'
                  | Media| Nav  | Mouse|   | Sym  | Num  | Fun  |
                  | Esc  | Space| Tab  |   | Enter| Bksp | Del  |
                  |      |      |      |   |      |      | Fn   |
                  ---------------------'   ---------------------'
```

- Home row mods: A=GUI, R=Alt, S=Ctrl, T=Shift (mirrored on right)
- Thumb keys activate layers when held, produce keys when tapped
- **Double-tap Del** sends F13 (mapped to Mac Fn via Karabiner)

## Nav Layer

```
,-------------------------------------.          ,----------------------------------.
| Slack|Ghostty|VsCode|IntelliJ|  Zen |          | Redo | Paste| Copy |  Cut | Undo |
|------+-------+------+--------+------|          |------+------+------+------+------|
| Cmd  |  Alt  | Ctrl | Shift  |LogSeq|          |CapsWd|  <-  |   v  |   ^  |  ->  |
|------+-------+------+--------+------+          +------+------+------+------+------|
|      |       |      |        |Claude|          |Insert| Home | PgDn | PgUp | End  |
`--------------+------+--------+------+---|   |--+------+------+------+-------------'
```

## Num Layer

```
,----------------------------------.          ,----------------------------------.
|  [   |  7   |  8   |  9   |  ]   |          |      |      |  Å   |  Ä   |  Ö   |
|------+------+------+------+------|          |------+------+------+------+------|
|  ;   |  4   |  5   |  6   |  =   |          |      | Shift| Ctrl |OS-Alt|  Cmd |
|------+------+------+------+------+          +------+------+------+------+------|
|  `   |  1   |  2   |  3   |  \   |          |      |      |      |      |      |
`-------------+------+------+------+---|   |--+------+------+------+-------------'
                  |  .   |  0   |  -   |   |      |      |      |
                  ---------------------'   ---------------------'
```

- **OS-Alt** is a one-shot mod: tap once, then tap a number for Alt+Number (e.g. tmux layout select) without holding two keys

## Sym Layer

```
,----------------------------------.          ,----------------------------------.
|  {   |  &   |  *   |  (   |  }   |          |      |      |      |      |      |
|------+------+------+------+------|          |------+------+------+------+------|
|  :   |  $   |  %   |  ^   |  +   |          |      | Shift| Ctrl |  Alt |  Cmd |
|------+------+------+------+------+          +------+------+------+------+------|
|  ~   |  !   |  @   |  #   |  |   |          |      |      |      |      |      |
`-------------+------+------+------+---|   |--+------+------+------+-------------'
                  |  (   |  )   |  _   |   |      |      |      |
                  ---------------------'   ---------------------'
```

## Fun Layer

```
,----------------------------------.          ,----------------------------------.
|  F12 | F7   | F8   | F9   |PrtScn|          |      |      |      |      |      |
|------+------+------+------+------|          |------+------+------+------+------|
|  F11 | F4   | F5   | F6   | ScLck|          |      | Shift| Ctrl |  Alt |  Cmd |
|------+------+------+------+------+          +------+------+------+------+------|
|  F10 | F1   | F2   | F3   | Pause|          |      |      |      |      |      |
`-------------+------+------+------+---|   |--+------+------+------+-------------'
```

## Media Layer

```
,----------------------------------.          ,----------------------------------.
|      |      |      |      |      |          | Redo | Paste| Copy |  Cut | Undo |
|------+------+------+------+------|          |------+------+------+------+------|
| Cmd  |  Alt | Ctrl | Shift|      |          |      | Prev | VolDn| VolUp| Next |
|------+------+------+------+------+          +------+------+------+------+------|
|      |      |      |      |      |          |      |      |      |      |      |
`-------------+------+------+------+---|   |--+------+------+------+-------------'
                  |      |      |      |   | RClk | LClk | Mute |
                  ---------------------'   ---------------------'
```

## Tap Dance

- **Double-tap** any layer key to lock into that layer
- **Double-tap Del** sends F13 (configure Karabiner to map F13 -> Fn)

## Building

```bash
qmk compile -kb splitkb/kyria/rev1 -km mharlin
```
