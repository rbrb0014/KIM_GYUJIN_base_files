import smtplib
from email.mime.text import MIMEText

smtp = smtplib.SMTP('smtp.nave.com',465)
smtp.ehlo()
smtp.starttls()
smtp.login('rbrb0014','qawsedrf4827@')

msg = MIMEText('write your message here')
msg['Subject'] = '아니 이거 왜 작동 안해'
msg['To'] = 'kim@naver.com'
smtp.sendmail('rbrb0014@naver.com','rbrb0014@gmail.com',msg.as_string())

smtp.quit()