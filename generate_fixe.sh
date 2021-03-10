#!/bin/bash

ARG=$(cat values);
./push_swap $ARG | ./checker $ARG #| wc -l