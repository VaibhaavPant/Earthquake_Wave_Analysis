import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.signal import butter, filtfilt

# Load earthquake data from CSV
df = pd.read_csv("Sampledatabase.csv")  # Replace with your actual file name

# Simulation parameters
fs = 100  # Sampling frequency (Hz)

# Function to apply Butterworth low-pass filter
def butter_lowpass_filter(data, cutoff=15, fs=100, order=5):
    b, a = butter(order, cutoff / (0.5 * fs), btype='low')
    return filtfilt(b, a, data)

# Generate and plot waves for each earthquake event (each nation)
for _, row in df.iterrows():
    nation = row["Earthquake_ID"]
    freq = row["Frequency(Hz)"]
    duration = row["Durations(sec)"]
    
    # Create time vector for this earthquake
    t = np.linspace(0, duration, fs * duration)

    # Generate sine wave for this earthquake event
    wave = np.sin(2 * np.pi * freq * t)

    # Add noise
    noise = np.random.normal(0, 0.1, wave.shape)
    wave += noise

    # Apply filtering
    filtered_wave = butter_lowpass_filter(wave)

    # Plot individual earthquake wave (time-domain)
    plt.figure(figsize=(10, 4))
    plt.plot(t, wave, label="Raw Wave", color='b', alpha=0.6)
    plt.plot(t, filtered_wave, label="Filtered Wave", color='r', linestyle="dashed")
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.title(f"Earthquake Wave - {nation}")
    plt.legend()
    plt.grid()
    plt.show()

    # FFT Analysis
    fft_values = np.fft.fft(wave)
    frequencies = np.fft.fftfreq(len(t), d=1/fs)

    # Plot FFT spectrum for this earthquake
    plt.figure(figsize=(10, 4))
    plt.plot(frequencies[:len(frequencies)//2], np.abs(fft_values)[:len(frequencies)//2], color='g')
    plt.xlabel("Frequency (Hz)")
    plt.ylabel("Magnitude")
    plt.title(f"FFT Spectrum - {nation}")
    plt.grid()
    plt.show()
