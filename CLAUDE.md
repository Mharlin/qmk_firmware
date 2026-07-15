# QMK Firmware - mharlin

## My Keymap
- **Path**: `keyboards/splitkb/kyria/keymaps/mharlin/`
- **Keyboard**: Kyria rev1

## Building
```bash
qmk compile -kb splitkb/kyria/rev1 -km mharlin
```

## Flashing
```bash
qmk flash -kb splitkb/kyria/rev1 -km mharlin
```

## Keeping docs in sync
When changing `keymap.c` or `config.h`, update `keyboards/splitkb/kyria/keymaps/mharlin/readme.md` in the same change (layers, tap dance behavior, features) — it has drifted out of sync with the actual keymap in the past.

## Fork status
This repo is a fork of `qmk/qmk_firmware` (only `origin` is configured, no `upstream` remote). As of 2026-07-15 the fork's `master` is ~1900 commits / ~7 months behind `qmk/qmk_firmware` master. No other unmerged branches exist on the fork. Consider adding an `upstream` remote and periodically merging to pick up bug fixes and new keyboard support — do a full compile + flash test afterward since QMK occasionally changes config formats (e.g. `keyboard.json` migrations).
