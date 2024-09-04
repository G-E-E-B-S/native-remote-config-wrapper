export interface IRemoteConfigListener {

    onRemoteConfigInit(): void;
    onRemoteConfigLoaded(data: any): void;
    onRemoteConfigLoadFailed(): void;
}


export interface IRemoteConfig {    
    fetch(callback: Function): void;
}
