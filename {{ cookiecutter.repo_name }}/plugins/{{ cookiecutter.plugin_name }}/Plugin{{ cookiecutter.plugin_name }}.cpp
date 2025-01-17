/*
 * {{ cookiecutter.project_name }} audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: {{ cookiecutter.project_license }}
 *
 * Copyright (C) {{ cookiecutter.year }} {{ cookiecutter.author_name }} <{{ cookiecutter.email }}>
{%- if cookiecutter.project_license == 'MIT' %}
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
{%- endif %}
 */

#include <math.h>

#include "Plugin{{ cookiecutter.plugin_name }}.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

Plugin{{ cookiecutter.plugin_name }}::Plugin{{ cookiecutter.plugin_name }}()
    : Plugin(paramCount, 1, 0)  // paramCount params, 1 program(s), 0 states
{
    sampleRateChanged(getSampleRate());
    loadProgram(0);
}

// -----------------------------------------------------------------------
// Init

void Plugin{{ cookiecutter.plugin_name }}::initParameter(uint32_t index, Parameter& parameter) {
    if (index >= paramCount)
        return;

    parameter.ranges.min = 0.0f;
    parameter.ranges.max = 1.0f;
    parameter.ranges.def = 0.1f;
    parameter.hints = kParameterIsAutomable | kParameterIsLogarithmic;

    switch (index) {
        case paramVolume:
            parameter.name = "Volume";
            parameter.symbol = "volume";
            break;
    }
}

/**
  Set the name of the program @a index.
  This function will be called once, shortly after the plugin is created.
*/
void Plugin{{ cookiecutter.plugin_name }}::initProgramName(uint32_t index, String& programName) {
    switch (index) {
        case 0:
            programName = "Default";
            break;
    }
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void Plugin{{ cookiecutter.plugin_name }}::sampleRateChanged(double newSampleRate) {
    fSampleRate = newSampleRate;
}

/**
  Get the current value of a parameter.
*/
float Plugin{{ cookiecutter.plugin_name }}::getParameterValue(uint32_t index) const {
    return fParams[index];
}

/**
  Change a parameter value.
*/
void Plugin{{ cookiecutter.plugin_name }}::setParameterValue(uint32_t index, float value) {
    fParams[index] = value;

    switch (index) {
        case paramVolume:
            // do something when volume param is set
            break;
    }
}

/**
  Load a program.
  The host may call this function from any context,
  including realtime processing.
*/
void Plugin{{ cookiecutter.plugin_name }}::loadProgram(uint32_t index) {
    switch (index) {
        case 0:
            setParameterValue(paramVolume, 0.1f);
            break;
    }
}

// -----------------------------------------------------------------------
// Process

void Plugin{{ cookiecutter.plugin_name }}::activate() {
    // plugin is activated
}

void Plugin{{ cookiecutter.plugin_name }}::run(const float** inputs, float** outputs,
                                  uint32_t frames) {
    // get the left and right audio inputs
    const float* const inpL = inputs[0];
    const float* const inpR = inputs[1];

    // get the left and right audio outputs
    float* const outL = outputs[0];
    float* const outR = outputs[1];

    float vol = fParams[paramVolume];

    // apply gain against all samples
    for (uint32_t i=0; i < frames; ++i) {
        outL[i] = inpL[i] * vol;
        outR[i] = inpR[i] * vol;
    }
}

// -----------------------------------------------------------------------

Plugin* createPlugin() {
    return new Plugin{{ cookiecutter.plugin_name }}();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
