# Lab Report - Unix Shell Session

## أهم الأوامر المنفذة

### الجزء 1 - التنقل
```bash
pwd
mkdir -p ~/shell_lab/{notes,scripts,data}
cd ~/shell_lab && ls -la
touch notes/day1.txt notes/day2.txt data/users.txt
cp notes/day1.txt notes/day1_copy.txt
mv notes/day2.txt notes/day2_renamed.txt
```

### الجزء 2 - المتغيرات
```bash
COURSE=UnixShell
echo ${COURSE}
echo ${HOME} ${SHELL} ${PATH}
export PATH="$HOME/shell_lab/scripts:$PATH"
export PS1="[SHELL-LAB] \u@\h:\w$ "
```

### الجزء 3 - ملفات التهيئة
```bash
echo ${SHELL}
echo "alias ll='ls -lah'" >> ~/.bashrc
source ~/.bashrc
ll
```

### الجزء 4 - النصوص + Pipes + Redirection
```bash
wc data/users.txt
grep admin data/users.txt
head -n 3 data/users.txt
tail -n 2 data/users.txt
cat data/users.txt | tr 'a-z' 'A-Z'
cut -d ',' -f 1 data/sample.csv
grep admin data/users.txt > data/admins.txt
ls nonexistent 2> data/errors.log
```

### الجزء 5 - السكربت greet.sh
```bash
chmod +x scripts/greet.sh
./scripts/greet.sh Ahmad
echo $?
```

### الجزء 6 - إدارة العمليات
```bash
sleep 120 &
jobs
kill %1
```

### الجزء 7 - Git
```bash
git init
git add .
git commit -m "Initialize shell lab workspace"
git checkout -b feature/lab-notes
git commit -m "Update README with lab notes"
git log --oneline --graph --decorate
```

### الجزء 8 - SSH
```bash
ls -la ~/.ssh
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub
```

---

## أسئلة التقييم

**1. ما الفرق بين `>`  و `>>` و `&>`؟**
- `>` يكتب الخرج إلى ملف ويمسح محتواه إن كان موجودًا.
- `>>` يضيف الخرج إلى نهاية الملف دون مسحه.
- `&>` يعيد توجيه كلٍّ من stdout وstderr معًا إلى ملف.

**2. متى نستخدم `source` بدل `./script.sh`؟**
نستخدم `source` حين نريد تنفيذ السكربت في نفس بيئة الـ shell الحالية (لأخذ تأثير المتغيرات والـ alias). أما `./script.sh` فيشغّل السكربت في shell فرعي منفصل.

**3. ما الفرق بين `&&` و `||`؟**
- `&&` ينفّذ الأمر الثاني فقط إذا نجح الأول (exit code = 0).
- `||` ينفّذ الأمر الثاني فقط إذا فشل الأول (exit code ≠ 0).

**4. لماذا نستخدم الفروع في Git؟**
لعزل التغييرات التجريبية عن الكود الرئيسي، والعمل على ميزات متوازية دون التأثير على الفرع الرئيسي، ثم دمجها بأمان عند الاكتمال.

**5. ما وظيفة ssh-agent؟**
يخزّن مفاتيح SSH مؤقتًا في الذاكرة حتى لا تحتاج إلى إدخال كلمة المرور في كل اتصال، مما يسهّل العمل مع Git وSSH بشكل متكرر.
