@extends('public.main_layout')
@section('dynamic_content')
<h2>Students list</h2>
<p>{{count($records)}}</p>
@endsection()
