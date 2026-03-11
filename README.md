# Instructions to Run Jupyter Notebook

# Navigate to project directory
cd /path to project forlder/

# Create Venv
python -m venv bnn_env
# Activate venv
source bnn_env/Scripts/activate
# Linux/Mac:
source bnn_env/bin/activate

# Install dependencies
pip install -r requirements.txt

# Verify python versioin (3.10)
python --version 
pip list

# Open local jupyter notebook via terminal
jupyter notebook

# Deactivate venv
deactivate

# Commiting to GitHub without venv (lies too big)
# Step 1: Add to .gitignore
echo "bnn_env/" >> .gitignore

# Step 2: Remove from git tracking (keeps files locally)
git rm -r --cached Project/bnn_env/

# Step 3: Commit the removal
git add .gitignore
git commit -m "Remove virtual environment from tracking"

# Step 4: Clean the large files from git history
git filter-repo --path Project/bnn_env/ --invert-paths --force

# Step 5: Force push (required after history rewrite)
git remote add origin https://github.com/timtran600/EECE4632.git 
git push origin main --force
