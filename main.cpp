#include <iostream>
#include <SFML/Audio.hpp>
#include <algorithm>

int loudest = 0;
double average_amp_memory = 0;
int file_nr = 0;

double calculate_average(sf::SoundBuffer buffer)
{


    // Get the number of samples in the audio file
    std::size_t sampleCount = buffer.getSampleCount();

    // Get the array of audio samples
    const sf::Int16* samples = buffer.getSamples();

    // Calculate the average amplitude
    double amplitudeSum = 0.0;
    for (std::size_t i = 0; i < sampleCount; ++i) {
        // Get the absolute value of each sample and add it to the sum
        amplitudeSum += std::abs(samples[i]);
    }

    // Calculate the average amplitude
    double averageAmplitude = amplitudeSum / sampleCount;

    if(averageAmplitude > average_amp_memory)
    {
        loudest = file_nr;

    }
    file_nr++;
    return averageAmplitude;
}

double calculate_peak(sf::SoundBuffer buffer)
{
    // Get the number of samples in the audio file
    std::size_t sampleCount = buffer.getSampleCount();

    // Get the array of audio samples
    const sf::Int16* samples = buffer.getSamples();

    // Calculate the peak amplitude
    double peak_amp = 0.0;
    for (std::size_t i = 0; i < sampleCount; ++i) {
        if(std::abs(samples[i]) > peak_amp)
        {
            peak_amp = std::abs(samples[i]);
        }
    }

    return peak_amp;
}

int main()
{
    std::string file_name;
    std::string file_extension;
    int files_to_analyze;


    std::cout << "How many files do you want to analyze?" << std::endl;
    std::cin >> files_to_analyze;

    sf::SoundBuffer buffer[files_to_analyze];

    for (int i = 1; i <= files_to_analyze; i++)
    {
        std::cout << "File " << i << " name: " << std::endl;
        std::cin >> file_name;

        std::cout << "File extention: " << std::endl;
        std::cin >> file_extension;

        // Open audio file.

        if (!buffer[i-1].loadFromFile("./audio/" + file_name + "." + file_extension)) {
            std::cerr << "Error loading audio file" << std::endl;
            return -1;
        }


    }

    for(int i = 1; i <= files_to_analyze; i++)
    {
        std::cout << "File " << i << std::endl;
        std::cout << "Average Amplitude: " << calculate_average(buffer[i-1]) << std::endl;
        std::cout << "Peak Amplitude: " << calculate_peak(buffer[i-1]) << std::endl;
    }

    std::cout << "Loudest file: file "<< loudest << std::endl;

    return 0;
}
