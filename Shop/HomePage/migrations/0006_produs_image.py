# Generated by Django 3.0.4 on 2020-05-10 19:59

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('HomePage', '0005_auto_20200507_1457'),
    ]

    operations = [
        migrations.AddField(
            model_name='produs',
            name='image',
            field=models.ImageField(blank=True, null=True, upload_to=''),
        ),
    ]
