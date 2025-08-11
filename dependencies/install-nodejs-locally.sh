#!/bin/bash

# Remove old nodejs if needed
sudo apt remove nodejs npm

# Install nvm
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
source ~/.bashrc   # or ~/.zshrc if you use zsh

# Install latest Node.js
nvm install node

# Verify
node -v
npm -v
