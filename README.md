# Instructions to Run Jupyter Notebook
1. Navigate to project directory
cd /path to project forlder/

2. Create Venv
python -m venv bnn_env
3. Activate venv
source bnn_env/Scripts/activate
Linux/Mac:
source bnn_env/bin/activate

4. Install dependencies
pip install -r requirements.txt

5. Verify python versioin (3.10)
python --version 
pip list

6. Open local jupyter notebook via terminal
jupyter notebook

7. Navigate to project
project/phase1_software/phase1.ipynb

8. Deactivate venv
deactivate

# Commiting to GitHub without venv (lies too big)
1. Add to .gitignore
echo "bnn_env/" >> .gitignore

2. Remove from git tracking (keeps files locally)
git rm -r --cached Project/bnn_env/

3. Commit the removal
git add .gitignore
git commit -m "Remove virtual environment from tracking"

4.  Clean the large files from git history
git filter-repo --path Project/bnn_env/ --invert-paths --force

5. Force push (required after history rewrite)
git remote add origin https://github.com/timtran600/EECE4632.git 
git push origin main --force
