#!/usr/bin/python3

import question

DEBUG = True

class Answer(question.Answer):

  def __init__(self, words):
    self.words = {}
    for word in words:
      ordered = "".join(sorted(word))
      self.words[ordered] = word

  def Check(self, scrambled):
    ordered = "".join(sorted(scrambled))
    if ordered in self.words:
      return self.words[ordered]
    return None


class Answer1(Answer):

  def Decode(self, scrambled):
    if not scrambled: return ""
    res = self.Check(scrambled)
    if res: return res

    for i in range(1, len(scrambled)):
      first_scrambled = scrambled[:i]
      first = self.Check(first_scrambled)
      if DEBUG: print("first:", i, first, first_scrambled) 
      if first is None: continue
      second_scrambled = scrambled[i:]
      if DEBUG: print("second_scrambled:", second_scrambled)
      second = self.Decode(second_scrambled)
      if second is not None:
        res = ""
        res += first
        if second: res += " " + second
        return res

    return None


class Answer2(Answer):

  def Decode(self, scrambled):
    n = len(scrambled)
    reachable = [""] + [None]*n
    for start in range(0,n):
      if DEBUG: print("start:", start, reachable)
      if reachable[start] is None: continue
      for end in range(start+1, n+1):
        if DEBUG: print("end:", end, reachable)
        if reachable[end]: continue
        match = self.Check(scrambled[start:end])
        if match:
          if DEBUG: print("match")
          res = reachable[start]
          if len(res): res += " "
          reachable[end] = res + match 
    return reachable[n] 


ANSWERS = [
   Answer1,
   Answer2,
]
