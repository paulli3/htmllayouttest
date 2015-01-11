set gitBinpath=D:\Program Files (x86)\Git\bin
set workdir=D:\code\c\htmllayouttest
chdir %workdir%
d:

set path=%path%;%gitBinpath%;

git add *
git commit -m "upload normal" 
git push https://github.com/paulli3/htmllayouttest.git master

pause
