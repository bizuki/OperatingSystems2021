#!/bin/bash

sudo fallocate -l 60MB lofs.img
sudo losetup -f lofs.img
sudo mkfs -t ext4 lofs.img
mkdir lofsdisk
sudo mount lofs.img lofsdisk
sudo chmod 777 lofsdisk/
echo 'first' > lofsdisk/file1.txt
echo 'second' > lofsdisk/file2.txt