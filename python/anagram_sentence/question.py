#!/usr/bin/python3

import random

class Answer:
  def __init__(self, words):
    pass

  def Decode(self, scrambled):
    pass


SENTENCES = [
  "Hello you",
  "Alice and Cesar definitely are cool people",
  "They are going to the movies",
  "I like going to parties with friends or watching TV",
  "It is grossly unfair to suggest that the school was responsible for the accident",
]

WORDS = set()

def BuildWords():
  for sentence in SENTENCES:
    for word in sentence.split(" "):
      word = word.lower()
      WORDS.add(word)

BuildWords()

def Scramble(sentence):
  ret = ""
  for word in sentence.split(" "):
    word = word.lower()
    assert word in WORDS, word + " not in WORDS"
    word = list(word) 
    random.shuffle(word)
    word = "".join(word)
    ret += word 
  return ret


def main():
  for sentence in SENTENCES:
    print( Scramble(sentence) )

if __name__ == "__main__":
  main()
