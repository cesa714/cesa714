#!/usr/bin/python3

import unittest
import question
import answers

class TestAnagramSetence(unittest.TestCase):

  def testSentences(self):
    for answer in answers.ANSWERS:
      print(answer)
      answer = answer(question.WORDS)
      for sentence in question.SENTENCES:
        scrambled = question.Scramble(sentence)
        print("Test case: %s : %s : %s" % (
          str(answer), sentence, scrambled))
        expected = sentence.lower()
        result = answer.Decode(scrambled)
        self.assertEqual(expected, result)

  def testTricky(self):
    """python -m unittest test.TestStringMethods.testTricky"""
    for answer in answers.ANSWERS:
      print(answer)
      words = ["i", "am", "alice"]
      sentence = "Alice am I"
      expected = sentence.lower()
      answer = answer(words)

      scrambled = "ialceami"
      print("Test case: %s : %s : %s" % (
        str(answer), sentence, scrambled))
      result = answer.Decode(scrambled)
      self.assertEqual(expected, result)

      scrambled = "aliceami"
      print("Test case: %s : %s : %s" % (
        str(answer), sentence, scrambled))
      result = answer.Decode(scrambled)
      self.assertEqual(expected, result)

  def testBadInput(self):
    for answer in answers.ANSWERS:
      print(answer)
      words = ["a", "aa"]
      scrambled = "aaab"
      answer = answer(words)
      print("Test case: %s : %s" % (
        str(answer), scrambled))
      result = answer.Decode(scrambled)
      self.assertEqual(None, result)


if __name__ == '__main__':
  unittest.main()
