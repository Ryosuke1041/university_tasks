from django.shortcuts import render
from .models import Friend
from .forms import HelloForm

def index(request):
    params = {
        'title':'Hello',
        'message':'性別を選択してください',
        'form': HelloForm(),
        'data': [],
    }
    if (request.method == 'POST'):
        form = HelloForm(request.POST)
        if form.is_valid():
            gender = form.cleaned_data['gender']
            if gender == 'female':
                params['data'] = Friend.objects.filter(gender=True)  # 'female'をTrueに対応
            else:
                params['data'] = Friend.objects.filter(gender=False)  # 'male'をFalseに対応
            params['form'] = form
        else:
            params['data'] = Friend.objects.all()
    else:
        params['data'] = Friend.objects.all()
    return render(request, 'hello/index.html', params)