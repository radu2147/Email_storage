# Generated by Django 3.0.4 on 2020-05-15 19:20

import datetime
from django.db import migrations, models
from django.utils.timezone import utc


class Migration(migrations.Migration):

    dependencies = [
        ('Comm', '0017_auto_20200515_2209'),
    ]

    operations = [
        migrations.AlterField(
            model_name='comment',
            name='date',
            field=models.DateField(default=datetime.datetime(2020, 5, 15, 19, 20, 6, 415069, tzinfo=utc)),
        ),
    ]
