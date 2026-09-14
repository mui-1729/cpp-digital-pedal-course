# GitHubへ移す

この教材はローカルGit repositoryとして配布します。
ChatGPT側のGitHub connectorは既存repositoryの編集には対応していますが、今回の接続では**新規repository作成操作が提供されていない**ため、無関係な既存repositoryへ勝手に入れません。

## 方法A: Git bundleからclone

配布された`.bundle`がある場合:

```bash
git clone cpp-digital-pedal-course.bundle cpp-digital-pedal-course
cd cpp-digital-pedal-course
```

GitHub上で空repository `cpp-digital-pedal-course` を作成した後:

```bash
git remote add origin https://github.com/<your-name>/cpp-digital-pedal-course.git
git push -u origin main
```

SSHを使っているならremote URLをSSH形式に変更してください。

## 方法B: ZIP

ZIPを展開した場合:

```bash
cd cpp-digital-pedal-course
git init -b main
git add .
git commit -m "initial course"
git remote add origin <YOUR_REPOSITORY_URL>
git push -u origin main
```

bundle版にはこちらで作った初期commit historyが含まれます。
