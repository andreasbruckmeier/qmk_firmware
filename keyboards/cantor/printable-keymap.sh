#!/usr/bin/env bash

grep '^ .*\*' keymaps/my/keymap.c | sed 's/^ *\*[/]*//' | grep -v '/\*'

