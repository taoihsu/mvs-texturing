#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <math.h>

#include "util/exception.h"
#include "util/file_system.h"

/**
  * Class representing a histogram with a fixed number of bins
  * optimized to calculate approximate permilles.
  */
class Histogram {
    private:
        std::vector<int> bins;
        float min;
        float max;
        int num_values;

    public:
        /** Constructs a histogram with num_bins bins which clamps values to [_min, _max]. */
        Histogram(float _min, float _max, std::size_t num_bins);

        /** Adds a value to the histogram. The value is clamped to [min, max]. */
        void add_value(float value);

        /**
          * Saves the histogram to a .csv file.
          * @throws util::FileException
          */
        void save_to_file(std::string const & filename) const;

        /**
          * Returns the approximate permille.
          */
        float get_approximate_permille(float permille) const;
};
