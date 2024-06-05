from django.shortcuts import render
from .models import Friend

def index(request):
    data = Friend.objects.all().values_list('id', 'name')
    params = {
        'title':'Hello',
        'data': data,
    }
    return render(request, 'hello/index.html', params)