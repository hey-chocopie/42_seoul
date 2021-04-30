#!/bin/bash -e

RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

addons_list=("ambassador" "auto-pause" "csi-hostpath-driver" "dashboard" "default-storageclass" "efk" "freshpod" "gcp-auth" "gvisor" "helm-tiller" "ingress" "ingress-dns" "istio" "istio-provisioner" "kubevirt" "logviewer" "metallb" "metrics-server" "nvidia-driver-installer" "nvidia-gpu-device-plugin" "olm" "pod-security-policy" "registry" "registry-aliases" "registry-creds" "storage-provisioner" "storage-provisioner-gluster" "volumesnapshots")

introduce()
{
	echo -e $GREEN
	echo "by. hoylee, 21-04-21"
	echo "FT_services,start!"

	echo -e $WHITE
	echo -e $CYAN
	echo "=============================================================================================="
	echo -e $WHITE
	echo " 8888888888 88888888888          88        d88888b  8b   d8  88        88888888  8888888"
	echo " 888            888              88        88   88  88   88  88        88        88"
	echo " 888            888              88        88   88  88   88  88        88        88"
	echo " 8888888        888              8888888h  88   88  88   88  88        88888888  8888888"
	echo " 888            888              88888888  88   88  \"888888  88        88        88"
	echo " 888            888              88    88  88   88       8b  88        88        88"
	echo " 888            888              88    88  88   88      8b   8888888b  88        88"
	echo " 888            888   88888888   88    88  d88888b  8888b    88888888  88888888  8888888"
	echo -e $CYAN
	echo "=============================================================================================="
	echo -e $BLUE

	echo -e $CYAN
	echo -e $WHITE
}

more_addons()
{
	echo -e "addons 더 필요한게 있으면 입력하세요, 그냥 진행하려면 enter"
	echo -e "ex) ambassador or auto-pause "
	read word
	while [[ $word != '' ]];
	do
		flag1=1
		for value in "${addons_list[@]}"; do
		    if [ $word == $value ] ; then
				minikube addons enable $word
				minikube addons list
				flag1=2
				echo "add complete $word"
			fi
		done
		if [ $flag1 -eq 1 ] ; then
			echo "==================================================================="
			echo -e $RED"$word is not inside addons. addons list,"
			echo -e $WHITE
			echo "Please input addons name or if you dont need addons just put enter"
			echo "==================================================================="
		fi
		if [ $flag1 -eq 2 ] ; then
			echo -e "addons 더 필요한게 있으면 입력하세요, 그냥 진행하려면 enter"
			echo -e "ex) ambassador or auto-pause "
		fi
		read word
	done
}

minikube_setup()
{

	minikube delete
	minikube start --driver=virtualbox --cpus=2 #2
	minikube addons enable metrics-server #3
	minikube addons enable dashboard &> /dev/null
	#minikube addons enable metallb
	minikube addons list
	more_addons #addons 활성화
	echo 😻- complete addons..!
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
	# On first install only
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

	MINIKUBE_IP=$(minikube ip)
	#sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/yaml_metallb/metallb.yaml > srcs/yaml_metallb/metallb_complete.yaml
	kubectl apply -f srcs/yaml_metallb/metallb_complete.yaml
	eval $(minikube docker-env)
	echo $DOCKER_HOST
	echo -en $GREEN
	echo "Minikube is ready !"
	echo
}

make_images()
{
	images_kind=("nginx")
	# "wordpress" "mysql" "phpmyadmin" "ftps" "grafana" "influxdb")

	for kind in "${images_kind[@]}"
	do
		echo -en $WHITE
		echo "📲 Building $kind image..."
		echo -en $YELLOW
		docker build -t $kind-alpine srcs/$kind/
		echo "$kind === "
		# -t옵션은 tag임, 이름을 정해줄수 있음.
		echo -en $GREEN
		echo "📱 success built $kind image !"
		echo
		#image_build $kind
	done
	echo -en $WHITE
}

yaml_services()
{
	kubectl apply -f srcs/yaml_services/nginx.yaml
}

main()
{
	introduce
	minikube_setup
	make_images
	yaml_services

}

main
