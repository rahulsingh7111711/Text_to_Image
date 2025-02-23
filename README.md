# Text-to-Image Generation using Diffusers

## Overview

This project utilizes Hugging Face Diffusers and Transformers to generate images from text prompts using pre-trained models. The implementation is optimized with Gradio for an interactive UI and supports GPU acceleration via PyTorch.

## Features

Generates high-quality images from text prompts

Uses Stable Diffusion models from Hugging Face

Supports GPU acceleration for faster inference

Interactive UI using Gradio

Saves generated images for later use

## Usage

Run the Jupyter Notebook:

jupyter notebook Text_to_Image.ipynb

Or use Python directly:

python generate_image.py --prompt "A futuristic city skyline at sunset"

## Dependencies

Ensure the following Python libraries are installed:

pip install diffusers transformers gradio accelerate torch

## Running with GPU

To accelerate image generation using a GPU, ensure PyTorch is using CUDA:

import torch
print(torch.cuda.is_available())  # Should return True if GPU is available

## Contribution

Feel free to contribute by opening an issue or submitting a pull request!

## License

This project is licensed under the MIT License.
