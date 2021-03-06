/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SCOscillator.h"
#include "SCEnvelopeFollower.h"
#include "SCOnePoleFilter.h"
#include "SCBiquadFilter.h"
#include "SCBiquadFilterCoeff.h"

//==============================================================================
/**
*/
#define OversamplingIRLength 1024
class CrashSyncAudioProcessor : public juce::AudioProcessor
{
public:
    enum
    {
        kInputModeNormal,
        kInputModeEnvelope,
        kNumInputModes
    };

    //=============================================================================
    CrashSyncAudioProcessor();
    ~CrashSyncAudioProcessor() override;

    //=============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout & layouts) const override;
#endif

    void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

    //=============================================================================
    juce::AudioProcessorEditor * createEditor() override;
    bool hasEditor() const override;

    //=============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //=============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String & newName) override;

    //=============================================================================
    void getStateInformation(juce::MemoryBlock & destData) override;
    void setStateInformation(const void * data, int sizeInBytes) override;

private:
    void processSubrate();

    // parameter
    juce::AudioParameterFloat * m_pFrequency;
    juce::AudioParameterFloat * m_pThreshold;
    juce::AudioParameterFloat * m_pGain;
    juce::AudioParameterFloat * m_pEnvAttack;
    juce::AudioParameterFloat * m_pEnvRelease;
    juce::AudioParameterFloat * m_pPulseWidth;
    juce::AudioParameterFloat * m_pOutputVolume;
    juce::AudioParameterFloat * m_pTone;    
    juce::AudioParameterFloat * m_pInputFilterCutoff;
    juce::AudioParameterFloat * m_pMix;
    juce::AudioParameterFloat * m_pLfoRate;
    juce::AudioParameterFloat * m_pLfoDepth;
    juce::AudioParameterFloat * m_pOscPhase;

    juce::AudioParameterInt * m_pWaveform;
    juce::AudioParameterInt * m_pInputMode;
    juce::AudioParameterInt * m_pPolyBlep;
    juce::AudioParameterInt * m_pOversample;

    SCDsp::SCOscillator m_OscillatorL;
    SCDsp::SCOscillator m_OscillatorR;
    SCDsp::SCOscillator m_Lfo;
    SCDsp::SCEnvelopeFollower m_EnvelopeFollowerL;
    SCDsp::SCEnvelopeFollower m_EnvelopeFollowerR;
    SCDsp::SCOnePoleFilter m_FilterL;
    SCDsp::SCOnePoleFilter m_FilterR;
    SCDsp::SCMultibandBiquadFilter<1> m_InputFilterL;
    SCDsp::SCMultibandBiquadFilter<1> m_InputFilterR;

    std::unique_ptr<juce::dsp::Oversampling<float>> m_pOversampler;

    //=============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CrashSyncAudioProcessor)
};

