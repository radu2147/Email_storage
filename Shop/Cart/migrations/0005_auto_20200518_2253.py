# Generated by Django 3.0.4 on 2020-05-18 19:53

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Cart', '0004_wishlist'),
    ]

    operations = [
        migrations.AddField(
            model_name='cart',
            name='gram',
            field=models.IntegerField(default=0),
        ),
        migrations.AddField(
            model_name='cart',
            name='inscr',
            field=models.CharField(default='', max_length=30),
        ),
    ]
