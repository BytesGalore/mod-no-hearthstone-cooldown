#!/usr/bin/env bash

## GETS THE CURRENT MODULE ROOT DIRECTORY
MOD_NO_HEARTHSTONE_COOLDOWN_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_NO_HEARTHSTONE_COOLDOWN_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_NO_HEARTHSTONE_COOLDOWN_ROOT"/conf/conf.sh" ]; then
    source $MOD_NO_HEARTHSTONE_COOLDOWN_ROOT"/conf/conf.sh"
fi
