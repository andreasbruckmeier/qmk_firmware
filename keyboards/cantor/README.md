
sudo apt install -y git python3-pip
python3 -m pip install --user qmk
qmk setup

qmk compile -kb cantor -km my

