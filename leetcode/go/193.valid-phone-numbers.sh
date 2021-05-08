#!/bin/bash

# grep 
# grep "\(^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$\)\|^([0-9]\{3\}) [0-9]\{3\}-[0-9]\{4\}$" file.txt

# bash
cat file.txt | while read line
do
    if [[ ${line} =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]] || [[ ${line} =~ ^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]] 
    then
        echo ${line}
    fi
done