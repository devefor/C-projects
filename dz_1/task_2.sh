#!/bin/bash

sudo -u user2 cp /opt/hw1/datasets.tar.gz /opt/user2_for_user3/
sudo -u user2 chmod 701 /opt/user2_for_user3 & sudo -u user2 chmod 604 /opt/user2_for_user3/datasets.tar.gz
