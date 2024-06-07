from django import forms

class HelloForm(forms.Form):
    gender = forms.fields.ChoiceField(label='GENDER',choices=(('female', 'female'), ('male', 'male')))