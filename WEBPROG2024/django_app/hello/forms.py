from django import forms

class HelloForm(forms.Form):
    gender = forms.fields.ChoiceField(label='GENDER', choice = ('female', 'male'))