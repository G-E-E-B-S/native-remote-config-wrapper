import { IRemoteConfig, IRemoteConfigListener } from "../IRemoteConfig";

declare var remoteconfig;

export class RemoteConfigGameHelper implements IRemoteConfig {

    private firebaseAppgetter: any = null;
    private readonly firebaseRemoteConfig: any = null;
    private _listener: IRemoteConfigListener;
    private _fetchCallback: Function;

    constructor(firebaseAppgetter: any, listener: IRemoteConfigListener) {
        this.firebaseAppgetter = firebaseAppgetter;
        this.firebaseRemoteConfig = remoteconfig.getInstance(this.firebaseAppgetter);
        this.setListener();
    }

    setListener(listener = {} as any): void {

        listener.onRemoteConfigInit = ()=> {

            console.log(">> remote config data init: ");
        };
        listener.onRemoteConfigLoaded = (configData) => {
            console.log(">> remote config data loaded: ", configData);
            
            for(let key in configData) {
                console.log(">>remote config data key: ", key, "value: ", configData[key]);
            }
            if(this._fetchCallback) this._fetchCallback(configData);
        };
        listener.onRemoteConfigLoadFailed = ()=> {

            console.log(">> remote config data failed: ");
        };
        this._listener = listener;
        remoteconfig.setListener(this._listener);
    }

    fetch(callback: Function): void {        
        this._fetchCallback = callback;
        this.firebaseRemoteConfig.fetch();
    }
}

