# Tweet
Twitterのアカウントを見ると以下のツイートからFLAGを得られる。

[https://twitter.com/CyberRebeat/status/1038306822602416128:embed]

# CyberRebeatScripts
GitHubのhistoryから差分を見るとFLAGを得られる。

[https://github.com/ennach/CyberRebeatScripts/commit/86cc1779522ad0708ad0b829935b08ac42b2588d#diff-ead3ef58f3edf3aa6f10ea889f359d26:embed:cite]

# ChangeHistory
GitHubのissueを見るとcommitのhashがあるので、それを用いる。

単純に`git clone`してから`git reset --hard`を叩くが、fatal errorが出る。

調べると、githubのURLを用いれば良いとのこと。

https://github.com/ennach/ChangeHistory/commit/c476614bc439fe1910e494422b3aa207b776d486

にアクセスすると、FLAGが得られる。
