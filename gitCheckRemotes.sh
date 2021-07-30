remotes=$(git remote show)
for rmt in $remotes;
do
    git remote show $rmt
done
