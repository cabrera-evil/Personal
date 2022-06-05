cd Personal
git init
git remote rm origin
git add .
git commit -m 'Update'
git remote add origin https://github.com/cabrera-evil/Personal.git
git branch -M master
git push origin master