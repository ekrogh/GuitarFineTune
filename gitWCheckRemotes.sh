remotes=$(git.exe remote show)
for rmt in $remotes;
do
    git.exe remote show $rmt
done
