#!/bin/bash

#Script for local map& reduce, ran on Eiger

cat trump_tweets_*.csv \
  | python3 mapper3.py \
  | sort \
  | python3 reducer3.py \
  > local_output.txt
