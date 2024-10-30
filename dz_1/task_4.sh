#!/bin/bash

temp=$(mktemp -d)

ssh-agent > $temp/ssh_agent_temp.sh
source $temp/ssh_agent_temp.sh > /dev/null 2>&1

for key in /opt/hw1/keys/*; do
    ssh-add "$key" > /dev/null 2>&1
done

ssh -o FingerprintHash=md5 -o StrictHostKeyChecking=no -o BatchMode=yes "user4@$MASTER_SERVER" -E $temp/LOGFILE -v /bin/true
md5=$(grep 'Server accepts key:' $temp/LOGFILE | sed -n 's/.*\(MD5:[a-f0-9:]*\).*/\1/p')

rm -Rf $temp
ssh-agent -k > /dev/null 2>&1

for key in /opt/hw1/keys/*; do
    key_fp=$(ssh-keygen -E md5 -lf $key | awk '{print $2}')
    if [ "$md5" = "$key_fp" ]; then
        echo "$key" | cut -d '_' -f 2
        echo "$md5"
    fi
done
