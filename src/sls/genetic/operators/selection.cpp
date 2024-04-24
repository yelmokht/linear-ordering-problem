// #include "selection.hpp"

// bool
// check_staganation(Population& population, int threshold)
// {
//     double sum = 0.0;
//     for (const auto& sol : population) {
//         sum += sol.quality;
//     }
//     double average_quality = sum / population.size();
    
//     static double prev_average_quality = average_quality; // Previous average quality
//     static int stagnation_count = 0; // Count for how long the stagnation persists
//     if (std::abs(average_quality - prev_average_quality) < threshold) {
//         stagnation_count++;
//         if (stagnation_count >= 10) { // Adjust the threshold and count as needed
//             return true; // Stagnation detected
//         }
//     } else {
//         stagnation_count = 0; // Reset stagnation count
//     }
//     prev_average_quality = average_quality; // Update previous average quality
//     return false;
// }

//  //Use Rank selection
// Population
// select(Population& population, Offspring& offspring, int m)
// {
//     population.insert(population.end(), offspring.begin(), offspring.end());
//     std::sort(population.begin(), population.end(), CompareSolutions);
//     population.resize(m); 
//     return population;
// }
