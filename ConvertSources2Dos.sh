#!/bin/bash

find . -name '*.cpp' | xargs unix2dos
find . -name '*.hpp' | xargs unix2dos
find . -name '*.h' | xargs unix2dos
