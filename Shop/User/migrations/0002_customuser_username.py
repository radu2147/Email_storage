# Generated by Django 3.0.4 on 2020-05-14 18:28

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('User', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='customuser',
            name='username',
            field=models.CharField(default='', max_length=50),
        ),
    ]