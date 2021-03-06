#include <algorithm>
#include <iostream>
#include <cmath>

#include "audio_in.h"
#include "constants.h"


bool openStream(PaStream **stream, window_data *data) {
    PaStreamParameters inputParameters;
    PaError err = paNoError;
    size_t totalFrames;
    size_t numSamples;

    numSamples = data->maxFrameIndex = totalFrames = WINDOW_LENGTH;
    data->frameIndex = 0;
    
    // make sure the sample array is initialized
    std::fill_n(data->recordedSamples, numSamples, 0.);
   
    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == paNoDevice) {
        std::cerr << "No default input device." << std::endl;
        return false;
    }
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = nullptr;

    err = Pa_OpenStream(
            stream,
            &inputParameters,
            nullptr,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,
            recordCallback,
            data
    );
    if (err != paNoError) {
        std::cerr << "Open stream failure: " << Pa_GetErrorText(err) << std::endl;
        return false;
    }

    return true;
}

bool recordWindow(PaStream *stream) {
    PaError err;

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cerr << "Start stream failure: " << Pa_GetErrorText(err) << std::endl;
        return false;
    }

    while ((err = Pa_IsStreamActive(stream)) == 1) {
        Pa_Sleep(50);
    }
    if (err < 0) {
        std::cerr << "Read stream failure: " << Pa_GetErrorText(err) << std::endl;
        return false;
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        std::cerr << "Stop stream failure: " << Pa_GetErrorText(err) << std::endl;
        return false;
    }

    return true;
}
