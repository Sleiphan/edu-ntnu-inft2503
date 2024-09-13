#include <iostream>
#include <string>

#define TEMP_COUNT 5
#define TEMP_LOWER_BOUND 10
#define TEMP_UPPER_BOUND 20

int main()
{
  std::cout << "Du skal skrive inn " << TEMP_COUNT << " temperaturer." << std::endl;

  int count_lo = 0;
  int count_mi = 0;
  int count_hi = 0;

  for (int temp_input_idx = 0; temp_input_idx < TEMP_COUNT; ++temp_input_idx)
  {
    printf("Temperatur nr %d: ", temp_input_idx + 1);
    std::string user_input;
    std::cin >> user_input;

    float temp = 0;

    try
    {
      temp = std::stof(user_input);
    }
    catch (const std::invalid_argument &e)
    {
      std::cout << "Skriv inn heltall eller desimaltall. Tekst tas ikke imot.\n";
      continue;
    }
    catch (const std::out_of_range &e)
    {
      std::cout << "Dette tallet er for stort!\n";
      continue;
    }

    count_lo += temp < TEMP_LOWER_BOUND;
    count_mi += temp >= TEMP_LOWER_BOUND && temp <= TEMP_UPPER_BOUND;
    count_hi += temp > TEMP_UPPER_BOUND;
  }

  printf("Antall under %d er %d\nAntall mellom %d og %d er %d\nAntall over %d er %d\n",
         TEMP_LOWER_BOUND,
         count_lo,
         TEMP_LOWER_BOUND,
         TEMP_UPPER_BOUND,
         count_mi,
         TEMP_UPPER_BOUND,
         count_hi);

  return 0;
}

#undef TEMP_COUNT
#undef TEMP_LOWER_BOUND
#undef TEMP_UPPER_BOUND