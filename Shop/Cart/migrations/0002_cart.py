# Generated by Django 3.0.4 on 2020-04-24 13:01

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('Cart', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Cart',
            fields=[
                ('produserrel_ptr', models.OneToOneField(auto_created=True, on_delete=django.db.models.deletion.CASCADE, parent_link=True, primary_key=True, serialize=False, to='Cart.ProdUserRel')),
                ('quantity', models.IntegerField(default=1)),
            ],
            bases=('Cart.produserrel',),
        ),
    ]