#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#define TEMP_COUNT 5
#define TEMP_LOWER_BOUND 10
#define TEMP_UPPER_BOUND 20
#define TEMPS_TO_READ 1024
#define FILE_PATH "Exercise_1/temps.txt"

void read_temperatures(double temperatures[], int length);

/// @brief Checks whether all values in a buffer is equal to a specific value
/// @param buffer The buffer to check
/// @param value The value to check against
/// @param size the size of the memory location, in bytes.
/// @return 1 if true, 0 if false
int buffer_equals_value(void *buffer, unsigned char value, size_t size)
{
  unsigned char *buffer_it = (unsigned char *)buffer;
  return (*buffer_it == value) && memcmp(buffer_it, buffer_it + 1, size - 1) == 0;
}

int main()
{
  double temperatures[TEMPS_TO_READ];
  read_temperatures(temperatures, TEMPS_TO_READ);

  if (buffer_equals_value(temperatures, -1, TEMPS_TO_READ * sizeof(double)))
  {
    return 1;
  }

  int count_lo = 0;
  int count_mi = 0;
  int count_hi = 0;

  for (double *temp = temperatures; temp < &temperatures[TEMPS_TO_READ]; ++temp)
  {
    count_lo += *temp < TEMP_LOWER_BOUND;
    count_mi += *temp >= TEMP_LOWER_BOUND && *temp <= TEMP_UPPER_BOUND;
    count_hi += *temp > TEMP_UPPER_BOUND;
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

void read_temperatures(double temperatures[], int length)
{
  // Initially, set all bits to 1 in the buffer. This is the return value if an error occurs. This must be done because this function does not allow for returning any error values.
  memset(temperatures, -1, length * sizeof(double));

  // The buffered file input stream that we use as a facade to read the contents of the file.
  std::ifstream file(FILE_PATH);

  // Check whether we successfully found and opened the file.
  if (!file)
  {
    std::cerr << "Error opening file!" << std::endl;
    return;
  }

  // Create a buffer, so that we do not touch the output buffer before we have successfully read all data. This must be done because this function does not allow for returning any error values.
  double *temp_buffer = new double[length];

  // A variable to keep track of which line we are at.
  int line_idx = 0;

  // A string variable that receives each line as we are reading through the file.
  std::string line;

  // Iterate over all lines, until we have filled the requirement or we reach EOF.
  while (std::getline(file, line) && line_idx < length)
  {
    try
    {
      temp_buffer[line_idx] = std::stod(line);
    }
    catch (const std::invalid_argument &e)
    {
      std::cerr << "Could not convert string at line " << (line_idx + 1) << " to a number" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
      std::cerr << "Value out of range at line " << (line_idx + 1) << std::endl;
    }

    ++line_idx;
  }

  // We are done reading from the file, so we should close it.
  file.close();

  // Time to return the values we read from the file. Everything seems to have gone well.
  memcpy(temperatures, temp_buffer, line_idx * sizeof(double));

  // As we have been using dynamic memory, we must remember to clean up after ourselves.
  delete[] temp_buffer;
}

#undef TEMP_COUNT
#undef TEMP_LOWER_BOUND
#undef TEMP_UPPER_BOUND
#undef TEMPS_TO_READ
#undef FILE_PATH