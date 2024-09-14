#include <iostream>
#include <string>

int main()
{
  // a)
  std::string word1, word2, word3;

  std::cout << "a)" << std::endl;
  std::cout << "Word 1: ";
  std::getline(std::cin, word1); // Using std::getline instead of std::cin to include all submitted words. Otherwise, "a sentence" would become "a".

  std::cout << "Word 2: ";
  std::getline(std::cin, word2);

  std::cout << "Word 3: ";
  std::getline(std::cin, word3);

  // b)
  std::cout << "\nb)" << std::endl;
  std::string sentence = word1 + " " + word2 + " " + word3;
  std::cout << "Your sentence is: \"" << sentence << "\"" << std::endl;

  // c)
  std::cout << "\nc)" << std::endl;
  std::cout << "Length of word 1:   " << word1.length() << std::endl;
  std::cout << "Length of word 2:   " << word2.length() << std::endl;
  std::cout << "Length of word 3:   " << word3.length() << std::endl;
  std::cout << "Length of sentence: " << sentence.length() << std::endl;

  // d)
  std::string sentence2 = sentence;

  // e)
  int num = std::min((size_t)12, sentence2.length()) - 9;
  if (num > 0)
    sentence2.replace(9, num, num, 'x');
  std::cout << "\ne)" << std::endl;
  std::cout << "Sentence: " << sentence << std::endl;
  std::cout << "XXXtence: " << sentence2 << std::endl;

  // f)
  std::string sentence_start = sentence.substr(0, std::min((size_t)5, sentence.length()));
  std::cout << "\nf)" << std::endl;
  std::cout << "Sentence:       " << sentence << std::endl;
  std::cout << "Sentence start: " << sentence_start << std::endl;

  // g)
  std::string query_text = "hallo";
  int contains_query_text = sentence.find(query_text);
  const std::string indicator_string = contains_query_text > -1 ? "CONTAINS" : "does NOT contain";
  std::cout << "\ng)" << std::endl;
  std::cout << "The sentence " << indicator_string << " \"" << query_text << "\"." << std::endl;

  // h)
  query_text = "er";
  int query_count = 0;
  int last_query_index = sentence.find(query_text, 0);
  while (last_query_index != -1)
  {
    ++query_count;
    last_query_index = sentence.find(query_text, last_query_index + query_text.length());
  }
  std::cout << "\nh)" << std::endl;
  std::cout << "The string \"" + query_text + "\" occurs " << query_count << " times" << std::endl;

  return 0;
}